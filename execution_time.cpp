#include <iostream>
#include <lldb/API/LLDB.h>

int main()
{
    lldb::SBDebugger::Initialize();
    lldb::SBDebugger debugger = lldb::SBDebugger::Create();
    debugger.SetAsync(false);

    lldb::SBTarget target = debugger.CreateTarget("main");

    // breakpoint
    lldb::SBBreakpoint b_st = target.BreakpointCreateByLocation("baseline.cpp", 10);
    lldb::SBBreakpoint b_ed = target.BreakpointCreateByLocation("baseline.cpp", 38);
    lldb::SBBreakpoint t_st = target.BreakpointCreateByLocation("threaded.cpp", 20);
    lldb::SBBreakpoint t_ed = target.BreakpointCreateByLocation("threaded.cpp", 45);

    // process
    lldb::SBProcess process = target.LaunchSimple(nullptr, nullptr, nullptr);

    lldb::StateType state = process.GetState();
    lldb::SBThread thread = process.GetThreadAtIndex(0);
    int count = 0;
    while (state != lldb::eStateExited && state != lldb::eStateInvalid)
    {
        if (state == lldb::eStateStopped)
        {
            // std::cout << count << ": " << thread.GetFrameAtIndex(0).GetLineEntry().GetFileSpec().GetFilename() << ":" << thread.GetFrameAtIndex(0).GetLineEntry().GetLine() << std::endl;
            if (thread.GetStopReason() == lldb::eStopReasonBreakpoint)
            {
                std::cout << "count" << count << std::endl;
                std::cout << "  " << thread.GetFrameAtIndex(0).GetFunctionName() << "  " << thread.GetFrameAtIndex(0).GetLineEntry().GetLine() << std::endl;
            }
            count += 1;
            thread.StepInstruction(true);
        }
        state = process.GetState();
    }
    lldb::SBDebugger::Terminate();
    return 0;
}
