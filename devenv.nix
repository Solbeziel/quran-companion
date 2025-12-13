{
  inputs,
  pkgs,
  lib,
  config,
  ...
}:

let
  qt6Packages = (import inputs.qt6-nixpkgs { inherit (pkgs.stdenv) system; }).kdePackages;
in
{
  env = {
    CMAKE_BUILD_TYPE = "Debug";
    CMAKE_GENERATOR = "Ninja Multi-Config";
    CMAKE_EXPORT_COMPILE_COMMANDS = 1;
  };

  languages.cplusplus.enable = true;

  packages =
    (with pkgs; [
      go-task
      cmake
      ninja
      clang-tools
      cmake-format
      crowdin-cli
    ])
    ++ (with qt6Packages; [
      qtbase
      qttools
      qtwayland
      qtmultimedia
      qtimageformats
      qttranslations
      wrapQtAppsHook
    ]);

  enterShell = ''
    echo "📦 Qt version: $(qmake -query QT_VERSION)"
  '';

  git-hooks.hooks = {
    cmake-format.enable = true;
    clang-format.enable = true;
    prettier.enable = true;
  };
}
