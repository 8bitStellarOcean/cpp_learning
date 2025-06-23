@startuml
state ab_scse_MainStateMachine_en {
    [*] --> ab_scse_MainWaitForStart_e
    ab_scse_MainWaitForStart_e --> ab_scse_MainEnableTimeTest_e
    
    state ab_scse_MainEnableTimeTest_e {
        :SubTaskReturnValue_bo = ab_scse_PerformEnableTimeTest();
    }
    ab_scse_MainEnableTimeTest_e --> ab_scse_MainWaitSconThresholdTest_e : if SubTaskReturnValue_bo == TRUE
    
    state ab_scse_MainWaitSconThresholdTest_e {
        if (ab_scse_StartSconThresholdTestIndicator_bo == TRUE) then (yes)
            --> ab_scse_MainSconThresholdTest_e
        else (no)
            --> [*]
        endif
    }
    
    state ab_scse_MainSconThresholdTest_e {
        :SubTaskReturnValue_bo = ab_scse_PerformSconThresholdTest();
    }
    ab_scse_MainSconThresholdTest_e --> ab_scse_MainFinished_e : if SubTaskReturnValue_bo == TRUE
    
    ab_scse_MainFinished_e --> [*]
}
@enduml