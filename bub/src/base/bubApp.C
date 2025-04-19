#include "bubApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
bubApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

bubApp::bubApp(InputParameters parameters) : MooseApp(parameters)
{
  bubApp::registerAll(_factory, _action_factory, _syntax);
}

bubApp::~bubApp() {}

void
bubApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<bubApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"bubApp"});
  Registry::registerActionsTo(af, {"bubApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
bubApp::registerApps()
{
  registerApp(bubApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
bubApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  bubApp::registerAll(f, af, s);
}
extern "C" void
bubApp__registerApps()
{
  bubApp::registerApps();
}
