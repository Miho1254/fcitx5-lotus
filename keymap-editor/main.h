/*
 * SPDX-FileCopyrightText: 2012-2018 CSSlayer <wengxt@gmail.com>
 * SPDX-FileCopyrightText: 2026 Nguyễn Hoàng Kỳ  <nhktmdzhg@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef _LOTUS_KEYMAP_EDITOR_MAIN_H_
#define _LOTUS_KEYMAP_EDITOR_MAIN_H_

#include <fcitxqtconfiguiplugin.h>

namespace fcitx::lotus {

    /**
     * @brief Fcitx5 plugin for the Lotus custom keymap editor.
     *
     * Loads the custom keymap editor widget.
     */
    class KeymapEditorPlugin : public FcitxQtConfigUIPlugin {
        Q_OBJECT
      public:
        /**
         * @brief Fcitx5 plugin metadata.
         */
        Q_PLUGIN_METADATA(IID FcitxQtConfigUIFactoryInterface_iid FILE "keymap-editor.json")

        /**
         * @brief Constructs a keymap editor plugin.
         * @param parent Parent widget.
         */
        explicit KeymapEditorPlugin(QObject* parent = nullptr);

        /**
         * @brief Creates a keymap editor widget.
         * @param key Configuration key.
         * @return Keymap editor widget.
         */
        FcitxQtConfigUIWidget* create(const QString& key) override;
    };
}

#endif
