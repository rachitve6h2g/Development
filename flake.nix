{
  description = "Minimal C development environment with gcc";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs =
    {
      self,
      nixpkgs,
    }:
    let
      system = "x86_64-linux"; # adjust for your system
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        name = "c-dev-shell";
        # buildInputs = with pkgs; [ bashInteractive ];
        packages = with pkgs; [
          gcc
          gnumake # optional, but usually needed
          gdb # optional, for debugging
          clang-tools
        ];

        shellHook = # bash
          ''
            export SHELL=/run/current-system/sw/bin/bash
            alias ec='emacsclient -c'
            echo "C dev environment ready to use"
          '';
      };
    };
}
