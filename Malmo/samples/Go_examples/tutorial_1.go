// ------------------------------------------------------------------------------------------------
// Copyright (c) 2016 Microsoft Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// ------------------------------------------------------------------------------------------------

// Tutorial sample #1: Run simple mission

package main

import (
	"fmt"
	"malmo"
	"os"
	"time"
)

func main() {

	// Create AgentHost
	agent_host := malmo.NewAgentHost()
	defer agent_host.Free()

	// Parse input
	err := agent_host.Parse(os.Args)
	if err != nil {
		fmt.Println(err)
		return
	}

	// Create Mission specification
	my_mission := malmo.NewMissionSpec()
	defer my_mission.Free()

	// Create Mission Record specification
	my_mission_record := malmo.NewMissionRecordSpec()
	defer my_mission_record.Free()

	// Attempt to start a mission:
	err = agent_host.StartMissionSimple(my_mission, my_mission_record)
	if err != nil {
		fmt.Println(err)
		return

	}

	// Loop until mission starts:
	fmt.Print("Waiting for the mission to start ")
	for {
		fmt.Print(".")
		time.Sleep(100 * time.Millisecond)
		world_state := agent_host.GetWorldState()
		if world_state.HasMissionBegun {
			break
		}
	}

	// Main Loop:
	fmt.Println()
	fmt.Print("Mission running ")
	for {
		time.Sleep(100 * time.Millisecond)
		world_state := agent_host.GetWorldState()
		if !world_state.IsMissionRunning {
			break
		}
	}
	fmt.Println("Mission ended")
}
