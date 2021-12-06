/*
 * AWS IoT Device SDK for Embedded C 202108.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef DEMO_CONFIG_H_
#define DEMO_CONFIG_H_

/**************************************************/
/******* DO NOT CHANGE the following order ********/
/**************************************************/

/* Logging related header files are required to be included in the following order:
 * 1. Include the header file "logging_levels.h".
 * 2. Define LIBRARY_LOG_NAME and  LIBRARY_LOG_LEVEL.
 * 3. Include the header file "logging_stack.h".
 */

/* Include header that defines log levels. */
#include "logging_levels.h"

/* Logging configuration for the Demo. */
#ifndef LIBRARY_LOG_NAME
    #define LIBRARY_LOG_NAME     "OTA_DEMO_HTTP"
#endif
#ifndef LIBRARY_LOG_LEVEL
    #define LIBRARY_LOG_LEVEL    LOG_INFO
#endif

#include "logging_stack.h"

/************ End of logging configuration ****************/

/**
 * @brief Details of the MQTT broker to connect to.
 *
 * @note Your AWS IoT Core endpoint can be found in the AWS IoT console under
 * Settings/Custom Endpoint, or using the describe-endpoint API.
 *
 * #define AWS_IOT_ENDPOINT               "...insert here..."
 */

/**
 * @brief AWS IoT MQTT broker port number.
 *
 * In general, port 8883 is for secured MQTT connections.
 *
 * @note Port 443 requires use of the ALPN TLS extension with the ALPN protocol
 * name. When using port 8883, ALPN is not required.
 */
#define AWS_MQTT_PORT    ( 8883 )

/**
 * @brief AWS IoT Core server port number for HTTPS connections.
 *
 * For this demo, an X.509 certificate is used to verify the client.
 *
 * @note Port 443 requires use of the ALPN TLS extension with the ALPN protocol
 * name being x-amzn-http-ca. When using port 8443, ALPN is not required.
 */
#ifndef AWS_HTTPS_PORT
    #define AWS_HTTPS_PORT    443
#endif


/**
 * @brief Path of the file containing the server's root CA certificate.
 *
 * This certificate is used to identify the AWS IoT server and is publicly
 * available. Refer to the AWS documentation available in the link below
 * https://docs.aws.amazon.com/iot/latest/developerguide/server-authentication.html#server-authentication-certs
 *
 * Amazon's root CA certificate is automatically downloaded to the certificates
 * directory from @ref https://www.amazontrust.com/repository/AmazonRootCA1.pem
 * using the CMake build system.
 *
 * @note This certificate should be PEM-encoded.
 * @note This path is relative from the demo binary created. Update
 * ROOT_CA_CERT_PATH to the absolute path if this demo is executed from elsewhere.
 */
#ifndef ROOT_CA_CERT_PATH
    #define ROOT_CA_CERT_PATH    "certificates/AmazonRootCA1.crt"
#endif

/**
 * @brief Path of the file containing the server's root CA certificate for TLS
 * authentication.
 *
 * The Baltimore Cybertrust Root CA Certificate is automatically downloaded to
 * the certificates directory using the CMake build system, from @ref
 * https://cacerts.digicert.com/BaltimoreCyberTrustRoot.crt.pem.
 *
 * @note This certificate should be PEM-encoded.
 */
#ifndef ROOT_CA_CERT_PATH_HTTP
    #define ROOT_CA_CERT_PATH_HTTP    \
    "-----BEGIN CERTIFICATE-----\n" \
    "MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n" \
    "ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\n" \
    "b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n" \
    "MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\n" \
    "b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n" \
    "ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n" \
    "9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n" \
    "IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\n" \
    "VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n" \
    "93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\n" \
    "jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\n" \
    "AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\n" \
    "A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n" \
    "U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\n" \
    "N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\n" \
    "o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\n" \
    "5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\n" \
    "rqXRfboQnoZsG4q5WTP468SQvvG5\n" \
    "-----END CERTIFICATE-----\n";
#endif

/**
 * @brief Path of the file containing the client certificate.
 *
 * Refer to the AWS documentation below for details regarding client
 * authentication.
 * https://docs.aws.amazon.com/iot/latest/developerguide/client-authentication.html
 *
 * @note This certificate should be PEM-encoded.
 *
 * #define CLIENT_CERT_PATH    "...insert here..."
 */

/**
 * @brief Path of the file containing the client's private key.
 *
 * Refer to the AWS documentation below for details regarding client
 * authentication.
 * https://docs.aws.amazon.com/iot/latest/developerguide/client-authentication.html
 *
 * @note This private key should be PEM-encoded.
 *
 * #define CLIENT_PRIVATE_KEY_PATH    "...insert here..."
 */

/**
 * @brief MQTT Client identifier.
 *
 * No two clients may use the same client identifier simultaneously.
 */
#ifndef CLIENT_IDENTIFIER
    #define CLIENT_IDENTIFIER    "testclient"
#endif

/**
 * @brief Configure application version.
 */

#define APP_VERSION_MAJOR         0
#define APP_VERSION_MINOR         9
#define APP_VERSION_BUILD         3

/**
 * @brief The name of the operating system that the application is running on.
 * The current value is given as an example. Please update for your specific
 * operating system.
 */
#define OS_NAME                   "Ubuntu"

/**
 * @brief The version of the operating system that the application is running
 * on. The current value is given as an example. Please update for your specific
 * operating system version.
 */
#define OS_VERSION                "18.04 LTS"

/**
 * @brief The name of the hardware platform the application is running on. The
 * current value is given as an example. Please update for your specific
 * hardware platform.
 */
#define HARDWARE_PLATFORM_NAME    "PC"

/**
 * @brief The name of the MQTT library used and its version, following an "@"
 * symbol.
 */
#define OTA_LIB                   "otalib@1.0.0"

#endif /* ifndef DEMO_CONFIG_H */
