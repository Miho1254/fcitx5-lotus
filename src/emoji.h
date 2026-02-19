/*
 * SPDX-FileCopyrightText: 2026 Nguyễn Hoàng Kỳ  <nhktmdzhg@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/**
 * @file emoji.h
 * @brief Emoji search and loading utilities.
 */

#ifndef EMOJI_H
#define EMOJI_H

#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

/**
 * @brief Single emoji entry with trigger and output.
 */
struct EmojiEntry {
    std::string trigger; ///< Trigger text (e.g., "smile")
    std::string output;  ///< Actual emoji character
};

#include "emoji_data.h"

/**
 * @brief Emoji loader with fuzzy search capability.
 *
 * Loads emoji list and provides fuzzy matching search.
 */
class EmojiLoader {
  private:
    std::vector<EmojiEntry> emojiList; ///< Internal emoji storage

  public:
    /**
     * @brief Constructs loader and initializes emoji list.
     */
    EmojiLoader() {
        emojiList = EMOJI_LIST;
    }

    /**
     * @brief Searches emoji by prefix with fuzzy matching.
     * @param prefix Search query.
     * @return Sorted list of matching emojis.
     */
    std::vector<EmojiEntry> search(const std::string& prefix) {
        if (prefix.empty())
            return {};

        struct EmojiEntryFuzzy {
            EmojiEntry entry;
            int        score;
        };
        std::vector<EmojiEntryFuzzy> results;

        for (const auto& entry : emojiList) {
            int    score              = 0;
            size_t queryIndex         = 0;
            int    lastMatchIndex     = -1;
            int    consecutiveMatches = 0;
            int    firstMatchIndex    = -1;

            for (size_t i = 0; i < entry.trigger.size() && queryIndex < prefix.size(); ++i) {
                if (entry.trigger[i] == prefix[queryIndex]) {
                    if (queryIndex == 0)
                        firstMatchIndex = i;

                    if (lastMatchIndex != -1 && (int)i == lastMatchIndex + 1) {
                        ++consecutiveMatches;
                        score += (20 * consecutiveMatches);
                    } else {
                        consecutiveMatches = 0;
                    }

                    if (i == 0 || entry.trigger[i - 1] == '_' || entry.trigger[i - 1] == '-') {
                        score += 50;
                    }

                    lastMatchIndex = i;
                    ++queryIndex;
                }
            }
            if (queryIndex == prefix.size()) {
                if (firstMatchIndex == 0)
                    score += 100;

                score -= static_cast<int>(entry.trigger.size());

                score -= (lastMatchIndex - firstMatchIndex);

                results.push_back({entry, score});
            }
        }

        std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
            if (a.score != b.score)
                return a.score > b.score;
            return a.entry.trigger.size() < b.entry.trigger.size();
        });

        std::vector<EmojiEntry> finalResults;
        for (const auto& result : results) {
            finalResults.push_back(result.entry);
        }
        return finalResults;
    }

    /**
     * @brief Gets total emoji count.
     * @return Number of emojis loaded.
     */
    size_t size() const {
        return emojiList.size();
    }
};

#endif // EMOJI_H
