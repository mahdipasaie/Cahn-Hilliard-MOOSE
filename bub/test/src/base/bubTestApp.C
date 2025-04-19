//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "bubTestApp.h"
#include "bubApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
bubTestApp::validParams()
{
  InputParameters params = bubApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

bubTestApp::bubTestApp(InputParameters parameters) : MooseApp(parameters)
{
  bubTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

bubTestApp::~bubTestApp() {}

void
bubTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  bubApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"bubTestApp"});
    Registry::registerActionsTo(af, {"bubTestApp"});
  }
}

void
bubTestApp::registerApps()
{
  registerApp(bubApp);
  registerApp(bubTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
bubTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  bubTestApp::registerAll(f, af, s);
}
extern "C" void
bubTestApp__registerApps()
{
  bubTestApp::registerApps();
}
