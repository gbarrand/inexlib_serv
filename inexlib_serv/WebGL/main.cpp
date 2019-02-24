// Copyright (C) 2010, Guy Barrand. All rights reserved.
// See the file inexlib_serv.license for terms.

#include "../inexlib_serv/main"

#include <exlib/app/WebGL/main_cpp>

int main(int argc,char** argv) {return exlib_main<inexlib_serv::context,inexlib_serv::main>("inexlib_serv",argc,argv);}

//exlib_build_use inlib expat
//exlib_build_use exlib png jpeg zlib inlib_glutess freetype kernel
