/*
 * SPDX-FileCopyrightText: 2012-2018 CSSlayer <wengxt@gmail.com>
 * SPDX-FileCopyrightText: 2026 Nguyễn Hoàng Kỳ  <nhktmdzhg@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include "main.h"
#include "editor.h"

namespace fcitx::lotus {
    KeymapEditorPlugin::KeymapEditorPlugin(QObject* parent) : FcitxQtConfigUIPlugin(parent) {}

    FcitxQtConfigUIWidget* KeymapEditorPlugin::create(const QString& key) {
        if (key == "custom_keymap") {
            return new KeymapEditor;
        }
        return nullptr;
    }
}