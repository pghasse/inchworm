#ifndef INCHWORMAPP_H
#define INCHWORMAPP_H

#include "MooseApp.h"

class InchwormApp;

template<>
InputParameters validParams<InchwormApp>();

class InchwormApp : public MooseApp
{
public:
  InchwormApp(InputParameters parameters);
  virtual ~InchwormApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* INCHWORMAPP_H */
