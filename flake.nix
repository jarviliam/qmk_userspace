{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    flake-utils = {
      url = "github:numtide/flake-utils";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  nixConfig = {
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        inherit pkgs;
        devShells.default = pkgs.mkShell {
          name = "qmk";
          buildInputs = with pkgs; [
            just
            keymap-drawer
            qmk
            stow
            watchexec
            wev
          ];

          shellHook = ''
            # Prevent the avr-gcc wrapper from picking up host GCC flags
            # like -iframework, which is problematic on Darwin
            unset NIX_CFLAGS_COMPILE_FOR_TARGET
          '';
        };
      }
    );
}
