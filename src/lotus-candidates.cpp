/*
 * SPDX-FileCopyrightText: 2026 Nguyễn Hoàng Kỳ  <nhktmdzhg@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */
#include "lotus.h"
#include "lotus-candidates.h"
#include "lotus-state.h"

#include <fcitx/inputpanel.h>
#include <fcitx/userinterface.h>

namespace fcitx {

    // EmojiCandidateWord implementation
    EmojiCandidateWord::EmojiCandidateWord(Text text, LotusState* state, const std::string& emojiOutput) :
        CandidateWord(std::move(text)), state_(state), emojiOutput_(emojiOutput) {}

    void EmojiCandidateWord::select(InputContext* inputContext) const {
        FCITX_UNUSED(inputContext);
        state_->ic_->commitString(emojiOutput_);

        state_->emojiBuffer_.clear();
        state_->emojiCandidates_.clear();

        state_->ic_->inputPanel().reset();
        state_->ic_->updateUserInterface(UserInterfaceComponent::InputPanel);
        state_->ic_->updatePreedit();
    }

    // AppModeCandidateWord implementation
    AppModeCandidateWord::AppModeCandidateWord(Text text, std::function<void(InputContext*)> callback) : CandidateWord(std::move(text)), callback_(std::move(callback)) {}

    void AppModeCandidateWord::select(InputContext* ic) const {
        if (callback_) {
            callback_(ic);
        }
    }

} // namespace fcitx
