/*
 * SPDX-FileCopyrightText: 2012-2018 CSSlayer <wengxt@gmail.com>
 * SPDX-FileCopyrightText: 2026 Nguyễn Hoàng Kỳ  <nhktmdzhg@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef _LOTUS_KEYMAP_EDITOR_EDITOR_H_
#define _LOTUS_KEYMAP_EDITOR_EDITOR_H_

#include <fcitxqtconfiguiwidget.h>
#include <QTableWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace fcitx::lotus {

    /**
     * @brief Lotus custom keymap editor.
     *
     * Allows editing of custom keymaps for the lotus input method using Qt GUI.
     */
    class KeymapEditor : public FcitxQtConfigUIWidget {
        Q_OBJECT
      public:
        /**
         * @brief Constructs a keymap editor.
         * @param parent Parent widget.
         */
        explicit KeymapEditor(QWidget* parent = nullptr);

        /**
         * @brief Returns the title of the keymap editor.
         * @return Title string.
         */
        QString title() override;

        /**
         * @brief Returns the icon of the keymap editor.
         * @return Icon string.
         */
        QString icon() override;

        /**
         * @brief Loads the custom keymap from the configuration file.
         */
        void load() override;

        /**
         * @brief Saves the custom keymap to the configuration file.
         */
        void save() override;

      private Q_SLOTS:

        /**
         * @brief Adds a new keymap entry.
         */
        void onAddClicked();

        /**
         * @brief Removes a keymap entry.
         */
        void onRemoveClicked();

        /**
         * @brief Loads a preset keymap.
         */
        void onLoadPresetClicked();

      private:
        QTableWidget*                                  tableWidget_;
        QLineEdit*                                     inputKey_;
        QComboBox*                                     comboAction_;
        QPushButton*                                   btnAdd_;
        QPushButton*                                   btnRemove_;
        QComboBox*                                     comboPreset_;
        QPushButton*                                   btnLoadPreset_;

        const std::vector<std::pair<QString, QString>> bambooActions_ = {
            {"XoaDauThanh", "Xóa dấu thanh"},
            {"DauSac", "Dấu sắc"},
            {"DauHuyen", "Dấu huyền"},
            {"DauHoi", "Dấu hỏi"},
            {"DauNga", "Dấu ngã"},
            {"DauNang", "Dấu nặng"},
            {"A_Â", "a -> â"},
            {"E_Ê", "e -> ê"},
            {"O_Ô", "o -> ô"},
            {"AEO_ÂÊÔ", "a/e/o -> â/ê/ô"},
            {"UOA_ƯƠĂ", "u/o/a -> ư/ơ/ă"},
            {"D_Đ", "d -> đ"},
            {"UO_ƯƠ", "u/o -> ư/ơ"},
            {"A_Ă", "a -> ă"},
            {"__ă", "ă"},
            {"_Ă", "Ă"},
            {"__â", "â"},
            {"_Â", "Â"},
            {"__ê", "ê"},
            {"_Ê", "Ê"},
            {"__ô", "ô"},
            {"_Ô", "Ô"},
            {"__ư", "ư"},
            {"_Ư", "Ư"},
            {"__ơ", "ơ"},
            {"_Ơ", "Ơ"},
            {"__đ", "đ"},
            {"_Đ", "Đ"},
            {"UOA_ƯƠĂ__Ư", "u/o/a -> ư/ơ/ă, ư"},
        };

        const std::map<QString, std::vector<std::pair<QString, QString>>> presets_ = {
            {"Telex",
             {{"z", "XoaDauThanh"},
              {"s", "DauSac"},
              {"f", "DauHuyen"},
              {"r", "DauHoi"},
              {"x", "DauNga"},
              {"j", "DauNang"},
              {"a", "A_Â"},
              {"e", "E_Ê"},
              {"o", "O_Ô"},
              {"w", "UOA_ƯƠĂ"},
              {"d", "D_Đ"}}},
            {"VNI",
             {{"0", "XoaDauThanh"},
              {"1", "DauSac"},
              {"2", "DauHuyen"},
              {"3", "DauHoi"},
              {"4", "DauNga"},
              {"5", "DauNang"},
              {"6", "AEO_ÂÊÔ"},
              {"7", "UO_ƯƠ"},
              {"8", "A_Ă"},
              {"9", "D_Đ"}}},
            {"VIQR",
             {{"0", "XoaDauThanh"},
              {"'", "DauSac"},
              {"`", "DauHuyen"},
              {"?", "DauHoi"},
              {"~", "DauNga"},
              {".", "DauNang"},
              {"^", "AEO_ÂÊÔ"},
              {"+", "UO_ƯƠ"},
              {"*", "UO_ƯƠ"},
              {"(", "A_Ă"},
              {"d", "D_Đ"}}},
            {"Microsoft layout",
             {{"8", "DauSac"},
              {"5", "DauHuyen"},
              {"6", "DauHoi"},
              {"7", "DauNga"},
              {"9", "DauNang"},
              {"1", "__ă"},
              {"!", "_Ă"},
              {"2", "__â"},
              {"@", "_Â"},
              {"3", "__ê"},
              {"#", "_Ê"},
              {"4", "__ô"},
              {"$", "_Ô"},
              {"0", "__đ"},
              {")", "_Đ"},
              {"[", "__ư"},
              {"{", "_Ư"},
              {"]", "__ơ"},
              {"}", "_Ơ"}}},
            {"Telex 2",
             {{"z", "XoaDauThanh"},
              {"s", "DauSac"},
              {"f", "DauHuyen"},
              {"r", "DauHoi"},
              {"x", "DauNga"},
              {"j", "DauNang"},
              {"a", "A_Â"},
              {"e", "E_Ê"},
              {"o", "O_Ô"},
              {"w", "UOA_ƯƠĂ__Ư"},
              {"d", "D_Đ"},
              {"]", "__ư"},
              {"[", "__ơ"},
              {"}", "_Ư"},
              {"{", "_Ơ"}}},
            {"Telex + VNI", {{"z", "XoaDauThanh"}, {"s", "DauSac"}, {"f", "DauHuyen"}, {"r", "DauHoi"},  {"x", "DauNga"},      {"j", "DauNang"}, {"a", "A_Â"},
                             {"e", "E_Ê"},         {"o", "O_Ô"},    {"w", "UOA_ƯƠĂ"},  {"d", "D_Đ"},     {"0", "XoaDauThanh"}, {"1", "DauSac"},  {"2", "DauHuyen"},
                             {"3", "DauHoi"},      {"4", "DauNga"}, {"5", "DauNang"},  {"6", "AEO_ÂÊÔ"}, {"7", "UO_ƯƠ"},       {"8", "A_Ă"},     {"9", "D_Đ"}}},
            {"Telex + VNI + VIQR",
             {{"z", "XoaDauThanh"}, {"s", "DauSac"},  {"f", "DauHuyen"}, {"r", "DauHoi"},      {"x", "DauNga"}, {"j", "DauNang"},  {"a", "A_Â"},      {"e", "E_Ê"},
              {"o", "O_Ô"},         {"w", "UOA_ƯƠĂ"}, {"d", "D_Đ"},      {"0", "XoaDauThanh"}, {"1", "DauSac"}, {"2", "DauHuyen"}, {"3", "DauHoi"},   {"4", "DauNga"},
              {"5", "DauNang"},     {"6", "AEO_ÂÊÔ"}, {"7", "UO_ƯƠ"},    {"8", "A_Ă"},         {"9", "D_Đ"},    {"'", "DauSac"},   {"`", "DauHuyen"}, {"?", "DauHoi"},
              {"~", "DauNga"},      {".", "DauNang"}, {"^", "AEO_ÂÊÔ"},  {"+", "UO_ƯƠ"},       {"*", "UO_ƯƠ"},  {"(", "A_Ă"},      {"\\\\", "D_Đ"}}},
            {"VNI Bàn phím tiếng Pháp",
             {{"&", "XoaDauThanh"},
              {"é", "DauSac"},
              {"\"", "DauHuyen"},
              {"'", "DauHoi"},
              {"(", "DauNga"},
              {"-", "DauNang"},
              {"è", "AEO_ÂÊÔ"},
              {"_", "UO_ƯƠ"},
              {"ç", "A_Ă"},
              {"à", "D_Đ"}}},
            {"Telex W",
             {{"z", "XoaDauThanh"},
              {"s", "DauSac"},
              {"f", "DauHuyen"},
              {"r", "DauHoi"},
              {"x", "DauNga"},
              {"j", "DauNang"},
              {"a", "A_Â"},
              {"e", "E_Ê"},
              {"o", "O_Ô"},
              {"w", "UOA_ƯƠĂ__Ư"},
              {"d", "D_Đ"}}}};
    };
}
#endif