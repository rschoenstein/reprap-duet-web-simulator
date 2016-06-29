#include "stdafx.h"
#include "ResponseProcessing.h"
#include "Utilities.h"
#include <map>

ResponseProcessing::ResponseProcessing()
{
}

ResponseProcessing::~ResponseProcessing()
{
}

void ResponseProcessing::Connect(map<string_t, string_t>& args, json::value& response) const
{
  response = json::value::object();

  if (args.size() <= 0 || args.count(L"password") < 1)
  {
    response[ERR] = 1;
  }
  else
  {
    response[ERR] = 0;
  }
}

void ResponseProcessing::Disconnect(json::value& response) const
{
  response = json::value::object();

  response[ERR] = 0;
}

void ResponseProcessing::Status(map<string_t, string_t>& args, json::value& response) const
{
  if (args.size() <= 0 || args.count(L"type") < 1)
  {
    return;
  }

  auto type = args[L"type"];

  response = json::value::object();

  auto status = web::json::value::object();
  auto coords = web::json::value::object();
  auto axesHomed = web::json::value::array(3);

  axesHomed[0] = web::json::value::number(1);
  axesHomed[1] = web::json::value::number(1);
  axesHomed[2] = web::json::value::number(1);

  coords[AXES_HOMED] = axesHomed;

  auto extr = web::json::value::array(3);

  extr[0] = web::json::value::number(0.0f);
  extr[1] = web::json::value::number(0.0f);
  extr[2] = web::json::value::number(0.0f);

  coords[EXTR] = extr;

  auto xyz = web::json::value::array(3);

  xyz[0] = web::json::value::number(0.0f);
  xyz[1] = web::json::value::number(0.0f);
  xyz[2] = web::json::value::number(0.0f);

  coords[XYZ] = xyz;

  status[COORDS] = coords;
  status[CURR_TOOL] = web::json::value::number(0);

  auto output = web::json::value::object();

  output[BEEP_DUR] = web::json::value::number(0);
  output[BEEP_FREQ] = web::json::value::number(0);
  output[MESSAGE] = web::json::value::string(L"Testing");

  status[OUTPUT] = output;

  auto params = web::json::value::object();

  params[ATX_POWER] = web::json::value::boolean(false);

  auto fanPercent = web::json::value::array(1);

  fanPercent[0] = web::json::value::number(0.0f);

  params[FAN_PERCENT] = fanPercent;
  params[SPEED_FACT] = web::json::value::number(100.0f);

  auto extrFacts = web::json::value::array(3);

  extrFacts[0] = web::json::value::number(100.0f);
  extrFacts[1] = web::json::value::number(100.0f);
  extrFacts[2] = web::json::value::number(100.0f);

  params[EXTR_FACTS] = extrFacts;

  status[SEQ] = web::json::value::number(0);

  auto sensors = web::json::value::object();

  sensors[PROBE_VAL] = web::json::value::number(0);
  sensors[FAN_RPM] = web::json::value::number(0);

  status[SENSORS] = sensors;

  auto temps = web::json::value::array(4);
  auto bed = json::value::object();
  auto heads = json::value::object();

  bed[CURRENT] = web::json::value::number(27.5f);
  bed[ACTIVE] = web::json::value::number(0.0);
  bed[STATE] = web::json::value::number(ToolState::Standby);

  auto current = json::value::array(3);

  current[0] = web::json::value::number(238.0f);
  current[1] = web::json::value::number(200.0f);
  current[2] = web::json::value::number(27.5f);

  heads[HEADS_CURRENT] = current;

  auto active = json::value::array(3);

  active[0] = web::json::value::number(238.0f);
  active[1] = web::json::value::number(238.0f);
  active[2] = web::json::value::number(238.0f);

  heads[HEADS_ACTIVE] = active;

  auto standby = json::value::array(3);

  standby[0] = web::json::value::number(238.0f);
  standby[1] = web::json::value::number(200.0f);
  standby[2] = web::json::value::number(200.0f);

  heads[HEADS_STANDBY] = standby;

  auto state = json::value::array(3);

  state[0] = ToolState::Active;
  state[1] = ToolState::Standby;
  state[2] = ToolState::Off;

  heads[HEADS_STATE] = state;

  status[HEADS] = heads;
  status[TIME] = web::json::value::number(30.5f);

  if (type == L"2")
  {
    status[COLD_EXTR_TEMP] = web::json::value::number(160.0f);
    status[COLD_RETRACT_TEMP] = web::json::value::number(90.0f);
    status[ENDSTOPS] = web::json::value::number(7);
    status[GEOMETRY] = json::value::string(L"delta");
    status[NAME] = json::value::string(L"TestPrinter");

    auto probe = json::value::object();

    probe[PROBE_THRESHOLD] = web::json::value::number(500);
    probe[PROBE_HEIGHT] = web::json::value::number(1.2f);
    probe[PROBE_TYPE] = web::json::value::number(4);

    status[PROBE] = probe;

    auto tools = json::value::array(3);

    for (size_t i = 0; i <= 3; ++i)
    {
      auto tool = json::value::object();

      tool[TOOL_NUMBER] = web::json::value::number(i);

      auto heaters = json::value::array(1);

      heaters[0] = web::json::value::number(i);

      tool[TOOL_HEATERS] = heaters;

      auto drives = json::value::array(1);

      drives[0] = web::json::value::number(i);

      tool[TOOL_EXTR_DRIVES] = drives;

      tools[i] = tool;
    }

    status[TOOLS] = tools;
  }
  else if (type == L"3")
  {
    status[CRNT_LAYER] = json::value::number(1);
    status[CRNT_LAYER_TIME] = json::value::number(5.0f);

    auto extrRaw = json::value::array(1);

    extrRaw[0] = json::value::number(0.0f);

    status[EXTR_RAW] = extrRaw;

    status[FRACT_PRINTED] = json::value::number(0.3f);
    status[FIRST_LAYER_DUR] = json::value::number(5.0f);
    status[FIRST_LAYER_HEIGHT] = json::value::number(2.0f);
    status[PRINT_DUR] = json::value::number(5.0f);
    status[WARM_DUR] = json::value::number(180.0f);

    status[TIME_LEFT] = json::value::number(1234.5f);
    status[FILAMENT] = json::value::number(3.5f);
    status[LAYER] = json::value::number(1.0f);
  }

  response[STATUS] = status;
}

void ResponseProcessing::GCode(map<string_t, string_t>& args, json::value& response)
{
  response = json::value::null();
}

void ResponseProcessing::Upload(map<string_t, string_t>& args, json::value& response)
{
  response = json::value::null();
}

void ResponseProcessing::Delete(map<string_t, string_t>& args, json::value& response)
{
  response = json::value::null();
}

void ResponseProcessing::Files(map<string_t, string_t>& args, json::value& response)
{
  response = json::value::null();
}

void ResponseProcessing::FileInfo(map<string_t, string_t>& args, json::value& response)
{
  response = json::value::null();
}

void ResponseProcessing::Move(map<string_t, string_t>& args, json::value& response)
{
  response = json::value::null();
}

void ResponseProcessing::Mkdir(map<string_t, string_t>& args, json::value& response)
{
  response = json::value::null();
}

void ResponseProcessing::GetConfigFile(map<string_t, string_t>& args, json::value& response)
{
  response = json::value::null();
}

void ResponseProcessing::PostConfigFile(map<string_t, string_t>& args, json::value& response)
{
  response = json::value::null();
}
