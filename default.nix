
{ stdenv, boost, cmake }:

stdenv.mkDerivation rec {
  pname = "cpp_playground";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ boost cmake ];
  # dontPatch = true;
  # dontFixup = true;
  # dontStrip = true;
  # dontPatchELF = true;
}