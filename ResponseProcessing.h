#pragma once

#include "stdafx.h"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;

class ResponseProcessing
{
public:
  ResponseProcessing();
  ~ResponseProcessing();

  void Connect(map<string_t, string_t> &args, json::value& response) const;
  void Disconnect(json::value& response) const;
  void Status(map<string_t, string_t> &args, json::value& response) const;
  void GCode(map<string_t, string_t> &args, json::value& response);
  void Upload(map<string_t, string_t> &args, json::value& response);
  void Delete(map<string_t, string_t> &args, json::value& response);
  void Files(map<string_t, string_t> &args, json::value& response);
  void FileInfo(map<string_t, string_t> &args, json::value& response);
  void Move(map<string_t, string_t> &args, json::value& response);
  void Mkdir(map<string_t, string_t> &args, json::value& response);
  void GetConfigFile(map<string_t, string_t> &args, json::value& response);
  void PostConfigFile(map<string_t, string_t> &args, json::value& response);

private:
  // Response constants. All Integers are 32-bit unsigned unless otherwise noted.
  // Common response keys
  const string_t ERR = L"err"; // 0: No Error
  // END Common response keys

  // rr_status response -----------------------------------------------------------------
  // Type 1: always send
  const string_t STATUS = L"status"; //Nested Object

  //->  Coordinates
  const string_t COORDS = L"coords"; //Nested Object
  const string_t AXES_HOMED = L"axesHomed"; //Array: int, 0 or 1, 3 items -> X, Y, Z
  const string_t EXTR = L"extr"; //Array
  const string_t XYZ = L"xyz"; //Array: float, 3 items -> X, Y, Z
  //->  END Coordinates

  const string_t CURR_TOOL = L"currentTool"; //Integer

  //->  Output
  const string_t OUTPUT = L"output"; //Nested Object
  const string_t BEEP_DUR = L"beepDuration"; //Integer
  const string_t BEEP_FREQ = L"beepFrequency"; //Integer????
  const string_t MESSAGE = L"message"; //Wide String
  //->  END Output

  //->  Parameters
  const string_t PARAMS = L"params"; //Nested Object
  const string_t ATX_POWER = L"atxPower"; //Boolean
  const string_t FAN_PERCENT = L"fanPercent"; //Array: float
  const string_t SPEED_FACT = L"speedFactor"; //Float
  const string_t EXTR_FACTS = L"extrFactors"; //Array: Float
  //->  END Parameters

  const string_t SEQ = L"seq"; //Integer

  //->  Sensors
  const string_t SENSORS = L"sensors"; //Nested Object
  const string_t PROBE_VAL = L"probeValue"; //Integer
  const string_t FAN_RPM = L"fanRPM"; //Integer
  //->  END Sensors

  //->  Temperatures
  const string_t TEMPS = L"temps"; //Nested Object

  //--->  Common
  const string_t CURRENT = L"current"; //Float
  const string_t ACTIVE = L"active"; //Float
  const string_t STANDBY = L"standby"; //Float
  const string_t STATE = L"state"; //Int
  //--->  END Common

  const string_t BED = L"bed"; //Nested Object: CURRENT, ACTIVE, STATE
  const string_t CHAMBER = L"chamber"; //Nested Object: CURRENT, ACTIVE, STATE
  const string_t HEADS = L"heads"; //Nested Object: Order arrays by tool #
  const string_t HEADS_CURRENT = CURRENT; //Array: float
  const string_t HEADS_ACTIVE = ACTIVE; //Array: float
  const string_t HEADS_STANDBY = STANDBY; //Array: float
  const string_t HEADS_STATE = STATE; //Array: int
  //->  END Temperatures

  const string_t TIME = L"time"; //Float: Time since last response

  // Type 2: extended status response
  const string_t COLD_EXTR_TEMP = L"coldExtrudeTemp"; //Float
  const string_t COLD_RETRACT_TEMP = L"coldRetractTemp"; //Float
  const string_t ENDSTOPS = L"endstops"; //16-bit Integer
  const string_t GEOMETRY = L"geometry"; //Char Array Pointer
  const string_t NAME = L"name"; //Char Array Pointer

  //->  Probe
  const string_t PROBE = L"probe"; //Nested Object
  const string_t PROBE_THRESHOLD = L"threshold"; //Integer
  const string_t PROBE_HEIGHT = L"height"; //Float
  const string_t PROBE_TYPE = L"type"; //Float
  //->  END Probe

  //-> Tools
  const string_t TOOLS = L"tools"; //Array: Nested Object
  const string_t TOOL_NUMBER = L"number"; //Integer
  const string_t TOOL_HEATERS = L"heaters"; //Array: Integer
  const string_t TOOL_EXTR_DRIVES = L"drives"; //Array: Integer
  //-> END Tools

  // Type 3: Print in progress.
  const string_t CRNT_LAYER = L"currentLayer"; //Integer
  const string_t CRNT_LAYER_TIME = L"currentLayerTime"; //Float
  const string_t EXTR_RAW = L"extrRaw"; //Array: Float
  const string_t FRACT_PRINTED = L"fractionPrinted"; //Float
  const string_t FIRST_LAYER_DUR = L"firstLayerDuration"; //Float
  const string_t FIRST_LAYER_HEIGHT = L"firstLayerHeight"; //Float
  const string_t PRINT_DUR = L"printDuration"; //Float
  const string_t WARM_DUR = L"warmUpDuration"; //Float
  const string_t TIME_LEFT = L"timeLeft"; //Float
  const string_t FILAMENT = L"filament"; //Float
  const string_t LAYER = L"layer"; //Float

  // END rr_status response -------------------------------------------------------------
};
