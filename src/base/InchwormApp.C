#include "InchwormApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<InchwormApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

InchwormApp::InchwormApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  InchwormApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  InchwormApp::associateSyntax(_syntax, _action_factory);
}

InchwormApp::~InchwormApp()
{
}

// External entry point for dynamic application loading
extern "C" void InchwormApp__registerApps() { InchwormApp::registerApps(); }
void
InchwormApp::registerApps()
{
  registerApp(InchwormApp);
}

// External entry point for dynamic object registration
extern "C" void InchwormApp__registerObjects(Factory & factory) { InchwormApp::registerObjects(factory); }
void
InchwormApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void InchwormApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { InchwormApp::associateSyntax(syntax, action_factory); }
void
InchwormApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
