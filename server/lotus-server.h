/*
 * SPDX-FileCopyrightText: 2025 Võ Ngô Hoàng Thành <thanhpy2009@gmail.com>
 * SPDX-FileCopyrightText: 2026 Nguyễn Hoàng Kỳ  <nhktmdzhg@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/**
 * @file lotus-server.h
 * @brief Uinput server for handling backspace and mouse events.
 *
 * This server runs as a separate process with elevated privileges to:
 * - Send backspace key events via uinput device
 * - Monitor mouse button presses via libinput
 * - Communicate with fcitx5 addon via Unix sockets
 */

#ifndef _LOTUS_SERVER_H_
#define _LOTUS_SERVER_H_

#include <atomic>
#include <fcntl.h>
#include <libinput.h>
#include <libudev.h>
#include <limits.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <poll.h>
#include <pwd.h>
#include <sched.h>
#include <string>
#include <sys/ioctl.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

/**
 * @brief Uinput device file descriptor.
 */
extern int uinput_fd_;

/**
 * @brief Global flag to control server running state.
 */
extern std::atomic<bool> g_running;

/**
 * @brief Signal handler for graceful shutdown.
 * @param sig Signal number (SIGTERM or SIGINT).
 */
void signal_handler(int sig);

/**
 * @brief Gets the current username.
 * @return Username string or "unknown" if cannot determine.
 */
std::string get_current_username();

/**
 * @brief Boosts process priority for real-time responsiveness.
 */
void boost_process_priority();

/**
 * @brief Pins process to performance cores (cores 0-3).
 */
void pin_to_pcore();

/**
 * @brief Sends a single backspace key event via uinput.
 */
void send_single_backspace();

/**
 * @brief Opens input device with restricted permissions.
 * @param path Device path.
 * @param flags Open flags.
 * @param user_data Unused user data.
 * @return File descriptor or negative errno on error.
 */
int open_restricted(const char* path, int flags, void* user_data);

/**
 * @brief Closes input device.
 * @param fd File descriptor to close.
 * @param user_data Unused user data.
 */
void close_restricted(int fd, void* user_data);

/**
 * @brief libinput interface callbacks.
 */
extern const struct libinput_interface interface;

/**
 * @brief Main entry point for the uinput server.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return Exit code (0 on success).
 */
int main(int argc, char* argv[]);

#endif // _LOTUS_SERVER_H_
