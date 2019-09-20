#!/bin/bash

cp agent_aiml /etc/init.d
cp agent_db /etc/init.d
cp agent_ota /etc/init.d
chmod a+x /etc/init.d/agent_aiml
chmod a+x /etc/init.d/agent_db
chmod a+x /etc/init.d/agent_ota
update-rc.d agent_ota defaults 98
update-rc.d agent_aiml defaults 99
update-rc.d agent_db defaults 99
