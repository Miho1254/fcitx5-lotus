set(KEYMAP_EDITOR_SRCS
    main.cpp
    editor.cpp
)

add_library(fcitx5-lotus-keymap-editor MODULE ${KEYMAP_EDITOR_SRCS})

set_target_properties(fcitx5-lotus-keymap-editor PROPERTIES
                      AUTOMOC TRUE)

target_link_libraries(fcitx5-lotus-keymap-editor
    Qt${QT_MAJOR_VERSION}::Core
    Qt${QT_MAJOR_VERSION}::Widgets
    Fcitx5Qt${QT_MAJOR_VERSION}::WidgetsAddons
    Fcitx5::Config
    Fcitx5::Utils
)

install(TARGETS fcitx5-lotus-keymap-editor DESTINATION ${CMAKE_INSTALL_LIBDIR}/fcitx5/qt${QT_MAJOR_VERSION})