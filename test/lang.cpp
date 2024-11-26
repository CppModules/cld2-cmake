//
// Created by 19254 on 24-11-26.
//
#include <iostream>
#include "CLD2/compact_lang_det.h"

int main() {
  std::vector<std::string> texts = {
    "Bonjour, comment ça va?",
    "你好呀！",
    "确保你的源文件实际上是以!",
    "今日はいい天気です",
    "天気です",
  };
  for (auto &text: texts) {
    bool is_plain_text = true; // 是否为纯文本
    bool is_reliable = false; // 是否可靠
    CLD2::Language language = CLD2::DetectLanguage(text.c_str(), text.size(), is_plain_text, &is_reliable);

    std::cout << "Detected language: " << CLD2::LanguageName(language) << std::endl;
    std::cout << "Language code: " << CLD2::LanguageCode(language) << std::endl;
    std::cout << "is_reliable: " << is_reliable << std::endl;
  }

  return 0;
}