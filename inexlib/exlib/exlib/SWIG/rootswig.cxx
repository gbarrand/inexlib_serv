// Copyright (C) 2010, Guy Barrand. All rights reserved.
// See the file exlib.license for terms.

#ifndef exlib_swig_rootswig
#define exlib_swig_rootswig

#include "swigmod.h"

// Language header in Source/Modules/swigmod.h
// Language code in Source/Modules/lang.cxx 

class rootswig : public Language {
  typedef Language parent;
public:
  virtual void main(int /*a_argc*/, char* /*a_argv*/[]) {
    ::printf("rootswig::main : dummy : 013.\n");    
  }
  virtual int top(Node* a_node) {
    String* name = Getattr(a_node,"name");
    String* outfile = Getattr(a_node,"outfile");
    ::printf("rootswig::top : dummy : name \"%s\", outfile \"%s\"\n",Char(name),Char(outfile));
    //Delete(name);
    //Delete(outfile);
    return parent::top(a_node);
  }
  virtual int classDeclaration(Node* a_node) {
    String* class_name = Getattr(a_node,"sym:name");
    String* real_classname = Getattr(a_node,"name");
    ::printf("rootswig::classDeclaration : dummy : \"%s\" \"%s\"\n",Char(class_name),Char(real_classname));
    //Delete(class_name);
    //Delete(real_classname);
    return Language::classDeclaration(a_node);
  }
  
  virtual int staticmemberfunctionHandler(Node* a_node) {
    String* name = Getattr(a_node,"sym:name");
    ::printf("rootswig::staticmemberfunctionHandler : dummy : \"%s\"\n",Char(name));
    //Delete(name);
    return SWIG_OK;
  }
  virtual int memberfunctionHandler(Node* a_node) {
    String* name = Getattr(a_node,"sym:name");
    ::printf("rootswig::memberfunctionHandler : dummy : \"%s\"\n",Char(name));
    //Delete(name);
    return SWIG_OK;
  }

  virtual int staticmembervariableHandler(Node* a_node) {
    String* name = Getattr(a_node,"sym:name");
    ::printf("rootswig::staticmembervariableHandler : dummy : \"%s\"\n",Char(name));
    //Delete(name);
    return SWIG_OK;
  }
  virtual int membervariableHandler(Node* a_node) {
    String* name = Getattr(a_node,"sym:name");
    ::printf("rootswig::membervariableHandler : dummy : \"%s\"\n",Char(name));
    //Delete(name);
    //Language::membervariableHandler(a_node);
    return SWIG_OK;
  }

  /*
  virtual int classHandler(Node* a_node) {
    String* class_name = Getattr(a_node,"sym:name");
    String* real_classname = Getattr(a_node,"name");
    ::printf("rootswig::classHandler : dummy : \"%s\" \"%s\"\n",Char(class_name),Char(real_classname));
    Delete(class_name);
    Delete(real_classname);
    return SWIG_OK;
  }
  virtual int classDirectorInit(Node*) {
    ::printf("rootswig::classDirectorInit : dummy.\n");
    return SWIG_OK;
  }
  virtual int classDirectorEnd(Node*) {
    ::printf("rootswig::classDirectorEnd : dummy.\n");
    return SWIG_OK;
  }
  */
  //virtual int constructorDeclaration(Node *n);
  //virtual int destructorDeclaration(Node *n);
  //virtual int accessDeclaration(Node *n);
  //virtual int namespaceDeclaration(Node *n);
  //virtual int staticmemberfunctionHandler(Node *n);

  //virtual int  classforwardDeclaration(Node *);
  //virtual int  insertDirective(Node *);
  //virtual int  importDirective(Node *);
};

extern "C" {

Language* swig_rootswig(void) {return new rootswig();}

}

//exlib_build_use skip

#endif
