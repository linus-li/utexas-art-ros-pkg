#ifndef __command_h__
#define __command_h__

#include <ros/ros.h>

#include <art_map/zones.h>

#include <art_nav/NavBehavior.h>
#include <art_nav/Mission.h>
#include <art_nav/NavigatorCommand.h>
#include <art_nav/NavigatorState.h>

#include "Blockage.h"
#include "Path.h"
#include "Event.h"

class CmdrFSM;

class Commander
{
  friend class CmdrFSM;			// state machine is a friend

 public:

  Commander(int verbosity, float limit, Graph* _graph, Mission* _mission,
	    const ZonePerimeterList& _zones);
  ~Commander();
  art_nav::Order command(const art_nav::NavigatorState &cur_navstate);

 private:
  int verbose;

  CmdrFSM* fsm;

  Graph* graph;
  Mission* mission;

  Blockages* blockages;

  ElementID current_way;
  const art_nav::NavigatorState *navstate; // current Navigator state
  art_nav::Order order;

  WayPointNode goal;			// next checkpoint goal
  WayPointNode goal2;			// following checkpoint

  ZonePerimeterList zones;

  Path* route;

  float speedlimit;
  int replan_num;

  // private methods:

  // return most urgent current event
  CmdrEvent current_event(void);

  // get next checkpoint, return true if any remain
  bool next_checkpoint(void);

  // prepare next Navigator order
  // TODO: improve argument type
  art_nav::Order prepare_order(art_nav::Behavior::_value_type behavior);

  // replan route, return true if successful
  bool replan_route();

  // set immediate checkpoint goals from mission
  void set_checkpoint_goals(void);
};


#endif
