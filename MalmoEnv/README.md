# MalmoEnv (Prototype) #

MalmoEnvis an OpenAI "gym" like Python Environment for Malmo/Minecraft, directly implemented Python to Java Minecraft.

A python "env" is created and used to run an agent in a Malmo mission. Each env has a remote Minecraft instance
associated to it (by IP and Port). For multi-agent missions, the first agent's (role 0) Minecraft is used as a 
coordinator to allow all agents to rendezvous on mission (re)starts (i.e. on env resets).

## Examples: ##

Install dependencies:

Java8 JDK, python3, git

`pip install gym lxml numpy pillow`

To prepare Minecraft (after cloning this repository with 
`git clone -b malmoenv https://github.com/Microsoft/malmo.git`):

`cd Minecraft`

`echo "malmomod.version=0.36.0"> ./src/main/resources/version.properties` (On Windows drop the double quotes)

Running a single agent example mission (run each command in different cmd prompt/shells):

`./launchClient.sh -port 9000 -env` or `launchClient.bat -port 9000 -env`

(In another shell) `cd MalmoEnv`

`python3 run.py --mission missions/mobchase_single_agent.xml --port 9000 --episodes 1`

A two agent example mission (run each command in different cmd prompt/shells):

`./launchClient.sh -port 9000 -env`

`./launchClient.sh -port 9001 -env`

The run script is given two ports - the first for the coordinator and a second for the other agent's Minecraft:

`python3 run.py --mission missions/mobchase_two_agents.xml --port 9000 --episodes 1 --role 0 --experimentUniqueId "test1"`

`python3 run.py --mission missions/mobchase_two_agents.xml --port 9000 --port2 9001 --episodes 1 --role 1  --experimentUniqueId "test1"`

## Running multi-threaded multi-agent examples: ##

`python3 python runmultiagent.py --mission missions/....xml`

## Installing with pip ##

If you install with `pip3 install malmoenv` then you can download the Minecraft mod 
(assuming you have git on the command line) with: 

`python3 -c "import malmoenv.bootstrap();malmoenv.bootstrap.download()`

The sample missions will be in ./MalmoPlatform/MalmoEnv/missions.

`malmoenv.bootstrap.launchMinecraft(10000)` can be used to start up the Malmo Minecraft Mod 
listening for MalmoEnv connections on port 10000 after downloading Malmo.

