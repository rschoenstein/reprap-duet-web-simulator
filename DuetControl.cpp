#include "stdafx.h"

#include "DuetControl.h"
#include "Utilities.h"
#include "ResponseProcessing.h"

DuetControl::DuetControl(string_t url) : m_listener(url)
{
  m_listener.support(methods::GET, std::bind(&DuetControl::handle_get, this, placeholders::_1));
  m_listener.support(methods::PUT, std::bind(&DuetControl::handle_put, this, placeholders::_1));
  m_listener.support(methods::POST, std::bind(&DuetControl::handle_post, this, placeholders::_1));
  m_listener.support(methods::DEL, std::bind(&DuetControl::handle_delete, this, placeholders::_1));
}

void DuetControl::handle_get(http_request message)
{
#ifndef NDEBUG
  ucout << message.to_string() << endl;
#endif

  auto paths = uri::split_path(uri::decode(message.relative_uri().path()));
  if (paths.empty())
  {
    message.reply(status_codes::BadRequest);
    return;
  }

  auto command = paths[0];
  auto args = uri::split_query(uri::decode(message.relative_uri().query()));
  auto responseProcessing = ResponseProcessing();
  auto status = status_codes::BadRequest;
  auto response = json::value::null();

  switch (Utilities::ParseCommand(command))
  {
    case Connect:
      responseProcessing.Connect(args, response);
      status = status_codes::OK;

      break;
    case Disconnect:
      responseProcessing.Disconnect(response);
      status = status_codes::OK;

      break;
    case Status:
      {
        responseProcessing.Status(args, response);

        if (response.type() != json::value::value_type::Null)
        {
          status = status_codes::OK;
        }

        break;
      }
    case Gcode:
      break;
    case Upload:
      break;
    case Delete:
      break;
    case Files:
      break;
    case FileInfo:
      break;
    case Move:
      break;
    case Mkdir:
      break;
    case Config:
      //TODO: return contents of config file
      break;
    default:
      break;
  }

  message.reply(status, response);
}

void DuetControl::handle_put(http_request message)
{
#ifndef NDEBUG
  ucout << message.to_string() << endl;
#endif
}

void DuetControl::handle_post(http_request message)
{
#ifndef NDEBUG
  ucout << message.to_string() << endl;
#endif
}

void DuetControl::handle_delete(http_request message)
{
#ifndef NDEBUG
  ucout << message.to_string() << endl;
#endif
}
