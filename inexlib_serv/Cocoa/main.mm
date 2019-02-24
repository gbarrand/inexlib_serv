// Copyright (C) 2010, Guy Barrand. All rights reserved.
// See the file inexlib_serv.license for terms.

#include "../inexlib_serv/main"

typedef inexlib_serv::main app_main_t;

#import <exlib/app/Cocoa/main.mm>

int main(int argc,char** argv) {return exlib_main<inexlib_serv::context,inexlib_serv::main>("inexlib_serv",argc,argv);}
 
