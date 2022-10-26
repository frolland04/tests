// std C++
#include <iostream>

// Boost Package
#include <boost/locale.hpp>
#include <boost/beast.hpp>
#include <boost/chrono.hpp>
#include <boost/log/common.hpp>

// Cppzmq Package
#include <zmq.hpp>

// Libnmea Package
#include <nmea.h>
#include <nmea/gpgll.h>
#include <nmea/gpgga.h>

// Spdlog Package
#include "spdlog/spdlog.h"

// JSON for Modern C++
#include "json/include/nlohmann/json.hpp"

// Libcpr Package
#include <cpr/cpr.h>

// SDBus++ Package
#include <sdbus-c++/sdbus-c++.h>

// BLE++ Package
/*#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <blepp/logging.h>
#include <blepp/pretty_printers.h>
#include <blepp/blestatemachine.h>
#include <blepp/lescan.h>*/

// Tiny BLE Package
#include <tinyb.hpp>

// Websocket++ Package
#include <websocketpp/connection.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/server.hpp>

// CppLinuxSerial Package
#include <CppLinuxSerial/SerialPort.hpp>

// OpenCV Package
#include <opencv2/opencv.hpp>

// POCO Package
#include <Poco/Foundation.h>
#include "Poco/Net/POP3ClientSession.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Exception.h"
#include "Poco/ThreadPool.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"


void horiz_break()
{
    std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

void test_cppzmq()
{
    horiz_break();
    zmq::context_t ctx;

    zmq::socket_t sock_s(ctx, zmq::socket_type::rep);
    sock_s.bind("inproc://test");

    zmq::socket_t sock_c(ctx, zmq::socket_type::req);
    sock_c.connect("inproc://test");
    sock_c.send(zmq::str_buffer("HELLO"), zmq::send_flags::none);

    zmq::message_t request;
    sock_s.recv(request, zmq::recv_flags::none);
    std::cout << "(zmq) Received : " << request.to_string() << std::endl;
}

void test_boost()
{
    horiz_break();
    boost::locale::generator gen;
    std::locale loc = gen("");
    std::locale::global(loc);
    std::cout.imbue(loc);

    std::cout << "(boost) This is upper case : " << boost::locale::to_upper("Hello World!") << std::endl;
}

void test_nmea()
{
    horiz_break();
    std::cout << "(libnmea)" << std::endl;
    char sentence[] = "$GPGLL,4916.45,N,12311.12,W,225444,A,*1D\r\n";
    std::cout << "sentence is " << (nmea_validate(sentence, strlen(sentence), 1)== 0 ? "valid." : "not valid." ) << std::endl;
    nmea_s * data = nmea_parse(sentence, strlen(sentence), 1);
    if (data != NULL)
    {
       std::cout << "parsed as datatype " << data->type << std::endl;
       if (data->type == NMEA_GPGLL)
       {
            nmea_gpgll_s * gpgll = (nmea_gpgll_s *) data;

            printf("GPGLL Sentence\n");
            printf("Longitude: %d %f %c\n", gpgll->longitude.degrees, gpgll->longitude.minutes, (char) gpgll->longitude.cardinal);
            printf("Latitude : %d %f %c\n", gpgll->latitude.degrees,  gpgll->latitude.minutes,  (char) gpgll->latitude.cardinal );
        }

        nmea_free(data);
    }
    else
    {
        std::cout << "sentence cannot be parsed." << std::endl;
    }
}

void test_spdlog()
{
    horiz_break();
    spdlog::info("(spdlog) HELLO WORLD!");
}

void test_json()
{
    horiz_break();
    nlohmann::json j;
    j["json_message"] = "HELLO WORLD!";
    j["pi"] = 3.1415;
    std::cout << j << std::endl;
}

void test_libcpr()
{
    horiz_break();
    char url[] = "https://api.github.com/repos/libcpr/cpr/contributors";
    std::cout << "(libcpr) GET " << url << std::endl;
    cpr::Response r = cpr::Get(cpr::Url{url},
                      cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
                      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
    std::cout << r.status_code << std::endl;
    std::cout << r.header["content-type"] << std::endl;
    std::cout << r.text.size() << std::endl;
}

void test_sdbuscpp()
{
    horiz_break();
    std::cout << "(sdbus++)" << std::endl;
    // Huh ?
}

void test_blepp()
{
    horiz_break();
    std::cout << "(ble++" << std::endl;
    // Huh ?
}

void test_tinyb()
{
    horiz_break();
    std::cout << "(tinyb)" << std::endl;

    try
    {
        tinyb::BluetoothManager * manager = tinyb::BluetoothManager::get_bluetooth_manager();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}

void test_websocketpp()
{
    horiz_break();
    std::cout << "(websocket++)" << std::endl;
    // Huh ?
}

void test_cppserial()
{
    horiz_break();
    std::cout << "(cppserial)" << std::endl;
    // Huh ?
}

void test_opencv()
{
    horiz_break();
    std::cout << "(opencv)" << std::endl;
    // Huh ?
}

void test_poco()
{
    horiz_break();
    std::cout << "(poco)" << std::endl;
    // Huh ?
}


int main(int argc, char** argv)
{
    horiz_break();
    std::cout << "(std) HELLO WORLD!" << std::endl;

    test_boost();
    test_cppzmq();
    test_nmea();
    test_spdlog();
    test_json();
    test_libcpr();
    test_sdbuscpp();
    test_blepp();
    test_tinyb();
    test_websocketpp();
    test_cppserial();
    test_opencv();
    test_poco();

    horiz_break();
    return 0;
}

