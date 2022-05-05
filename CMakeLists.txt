cmake_minimum_required(VERSION 3.16.3)

project(bill-manager)

set(SOURCES
    main.c
    src/app.c
    src/bill.c
    src/cli.c
    src/date.c
    src/help.c
    src/logs.c
    src/utils.c
)

add_executable(billman ${SOURCES})
