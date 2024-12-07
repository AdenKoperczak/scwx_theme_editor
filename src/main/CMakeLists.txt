project(app)

set(app_SRCS
  main.cpp
  mainwindow.cpp
  paletteeditdialog.cpp
  paletteeditdialog.ui
)

add_executable(scwx_theme_editor ${app_SRCS})
target_link_libraries(scwx_theme_editor PRIVATE Qt6::Widgets Qt6::WidgetsPrivate qt6ct-common)


install(TARGETS scwx_theme_editor DESTINATION ${CMAKE_INSTALL_BINDIR})

qt_generate_deploy_app_script(TARGET scwx_theme_editor
                              OUTPUT_SCRIPT deploy_script
                              NO_TRANSLATIONS
                              NO_UNSUPPORTED_PLATFORM_ERROR
                              PRE_EXCLUDE_REGEXES ".*qt6ct.*")

install(SCRIPT ${deploy_script}
        COMPONENT scwx_theme_editor
        DESTINATION ${CMAKE_INSTALL_BINDIR})
