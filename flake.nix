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
        packages = [
          pkgs.gcc
          pkgs.gnumake # optional, but usually needed
          pkgs.gdb # optional, for debugging
          pkgs.clang-tools
        ];

        shellHook = ''
          		  alias ec='emacsclient -c'
          		  echo "C dev environment ready to use"
          	'';
      };
    };
}
