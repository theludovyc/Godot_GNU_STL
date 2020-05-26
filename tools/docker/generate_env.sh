#!/bin/sh
echo -e "UID=`id -u`\nGID=`id -g`" > .env
echo -e "build=Release" >> .env