<AnimDB FragDef="Animations/Mannequin/ADB/PlayerFragmentIds.xml" TagDef="Animations/Mannequin/ADB/PlayerTags.xml">
 <FragmentList>
  <Idle>
   <Fragment BlendOutDuration="0.2" Tags="Rotate">
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="1DONE-BSpace_RotateRIFLE" flags="Loop"/>
    </AnimLayer>
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="aimpose_01" flags="Loop+ForceSkelUpdate"/>
    </AnimLayer>
   </Fragment>
   <Fragment BlendOutDuration="0.2" Tags="">
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="rifleAim_idle_3p" flags="Loop"/>
    </AnimLayer>
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="aimpose_01" flags="Loop+ForceSkelUpdate"/>
    </AnimLayer>
   </Fragment>
  </Idle>
  <Walk>
   <Fragment BlendOutDuration="0.2" Tags="">
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="2DONE-BSpace_MoveStrafeRIFLE" flags="Loop"/>
    </AnimLayer>
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="aimpose_01" flags="Loop+ForceSkelUpdate"/>
    </AnimLayer>
   </Fragment>
  </Walk>
  <IdleNoGun>
   <Fragment BlendOutDuration="0.2" Tags="Rotate">
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="1DONE-BSpace_Rotate" flags="Loop"/>
    </AnimLayer>
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="aimpose_01" flags="Loop+ForceSkelUpdate"/>
    </AnimLayer>
   </Fragment>
   <Fragment BlendOutDuration="0.2" Tags="">
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="idle_3p" flags="Loop"/>
    </AnimLayer>
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="aimpose_01" flags="Loop+ForceSkelUpdate"/>
    </AnimLayer>
   </Fragment>
  </IdleNoGun>
  <WalkNoGun>
   <Fragment BlendOutDuration="0.2" Tags="">
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="2DONE-BSpace_MoveStrafe" flags="Loop"/>
    </AnimLayer>
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="aimpose_01" flags="Loop+ForceSkelUpdate"/>
    </AnimLayer>
   </Fragment>
  </WalkNoGun>
  <RunNoGun>
   <Fragment BlendOutDuration="0.2" Tags="">
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="2DONE-BSpace_MoveStrafeRun" flags="Loop" speed="1.2"/>
    </AnimLayer>
    <AnimLayer>
     <Blend ExitTime="0" StartTime="0" Duration="0.2"/>
     <Animation name="aimpose_01" flags="Loop+ForceSkelUpdate"/>
    </AnimLayer>
   </Fragment>
  </RunNoGun>
 </FragmentList>
</AnimDB>
