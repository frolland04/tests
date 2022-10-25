// std C++
#include <iostream>

// Boost Package
#include <boost/locale.hpp>

// Cppzmq Package
#include <zmq.hpp>

// Libnmea Package
#include <nmea.h>
#include <nmea/gpgll.h>
#include <nmea/gpgga.h>

// Spdlog Package
#include "spdlog/spdlog.h"


void test_cppzmq()
{
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
    boost::locale::generator gen;
    std::locale loc = gen("");
    std::locale::global(loc);
    std::cout.imbue(loc);

    std::cout << "(boost) This is upper case : " << boost::locale::to_upper("Hello World!") << std::endl;
}

void test_nmea()
{
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
    spdlog::info("(spdlog) HELLO WORLD!");
}

int main(int argc, char** argv)
{
    std::cout << "(std) HELLO WORLD!" << std::endl;
    test_boost();
    test_cppzmq();
    test_nmea();
    test_spdlog();
    return 0;
}

