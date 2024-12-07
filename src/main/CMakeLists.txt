project(app)

set(app_SRCS
  main.cpp
  mainwindow.cpp
  paletteeditdialog.cpp
  paletteeditdialog.ui
)

add_executable(scwx_theme_editor ${app_SRCS})
target_link_libraries(scwx_theme_editor PRIVATE Qt6::Widgets Qt6::WidgetsPrivate qt6ct-common)
install(TARGETS scwx_theme_editor
        RUNTIME_DEPENDENCIES
          PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
          POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
                               "^(/usr)?/lib/.*\\.so(\\..*)?"
        DESTINATION ${CMAKE_INSTALL_BINDIR})
