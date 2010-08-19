//
// Navigator behaviors
//
//  Copyright (C) 2007 Austin Robot Technology
//  All Rights Reserved. Licensed Software.
//
//  This is unpublished proprietary source code of Austin Robot
//  Technology, Inc.  The copyright notice above does not evidence any
//  actual or intended publication of such source code.
//
//  PROPRIETARY INFORMATION, PROPERTY OF AUSTIN ROBOT TECHNOLOGY
//
//  $Id$
//
//  Author: Jack O'Quin
//

#ifndef __NAV_BEHAVIORS_H__
#define __NAV_BEHAVIORS_H__

#include <art_nav/Behavior.h>

class NavBehavior
{
public:

  // Navigator behaviors (lower numbers have higher priority)
  typedef enum
    {
      Abort,
      Quit,
      Pause,
      Run,
      Initialize,
      Go,
      None,
      N_behaviors
    } nav_behavior_t;

  // return behavior name as a C string
  const char *Name(void)
  {
    static const char *behavior_name[N_behaviors] =
      {
	"Abort",
	"Quit",
	"Pause",
	"Run",
	"Initialize",
	"Go",
	"None",
      };
    return behavior_name[this->behavior];
  }

  NavBehavior()
  {
    this->behavior = None;
  }

  NavBehavior(nav_behavior_t &ibehavior)
  {
    this->behavior = ibehavior;
  }

  NavBehavior(const art_nav::Behavior &behavior_msg)
  {
    this->behavior = (nav_behavior_t) behavior_msg.value;
  }

  ~NavBehavior();

  nav_behavior_t Value(void)
  {
    return this->behavior;
  }

  void operator=(const NavBehavior &newval)
  {
    this->behavior = newval.behavior;
  }

  bool operator==(const NavBehavior compare)
  {
    return this->behavior == compare.behavior;
  }

  bool operator!=(const NavBehavior compare)
  {
    return this->behavior != compare.behavior;
  }

  void operator=(const NavBehavior::nav_behavior_t &newbehavior)
  {
    this->behavior = newbehavior;
  }

  bool operator==(const nav_behavior_t &compare)
  {
    return this->behavior == compare;
  }

  bool operator!=(const nav_behavior_t &compare)
  {
    return this->behavior != compare;
  }

private:
  nav_behavior_t behavior;
};

#endif // __NAV_BEHAVIORS_H__
