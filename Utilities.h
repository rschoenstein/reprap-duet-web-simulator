#pragma once

#include "stdafx.h"

enum Command
{
  BadCommand,
  Connect,
  Disconnect,
  Status,
  Gcode,
  Upload,
  Delete,
  Files,
  FileInfo,
  Move,
  Mkdir,
  Config
};

enum Arg
{
  None,
  Pass,
  Name,
  Type,
  Code,
  Dir,
  FlagDirs,
  Old,
  New
};

enum ToolState
{
  Off,
  Standby,
  Active,
  Fault
};

class Utilities
{
public:
  inline static Command ParseCommand(const utility::string_t &command)
  {
    
    if(command == L"rr_connect")
    {
      return Connect;
    }

    if(command == L"rr_disconnect")
    {
      return Disconnect;
    }

    if(command == L"rr_status")
    {
      return Status;
    }

    if(command == L"rr_gcode")
    {
      return Gcode;
    }

    if(command == L"rr_upload")
    {
      return Upload;
    }

    if(command == L"rr_delete")
    {
      return Delete;
    }

    if(command == L"rr_files")
    {
      return Files;
    }

    if(command == L"rr_fileInfo")
    {
      return FileInfo;
    }

    if(command == L"rr_move")
    {
      return Move;
    }

    if(command == L"rr_mkdir")
    {
      return Mkdir;
    }

    return BadCommand;
  }

  inline static Arg ParseArguments(const utility::string_t &arg)
  {
    if(arg == L"password")
    {
      return Pass;
    }

    if(arg == L"name")
    {
      return Name;
    }

    if(arg == L"type")
    {
      return Type;
    }

    if(arg == L"gcode")
    {
      return Code;
    }

    if(arg == L"dir")
    {
      return Dir;
    }

    if(arg == L"flagDirs")
    {
      return FlagDirs;
    }

    if(arg == L"Old")
    {
      return Old;
    }

    if(arg == L"New")
    {
      return New;
    }

    return None;
  }
};
