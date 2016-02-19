/*
 * StepCompleter.hpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Péter Fankhauser
 *   Institute: ETH Zurich, Autonomous Systems Lab
 */

#pragma once

// Free Gait
#include "free_gait_core/TypeDefs.hpp"
#include "free_gait_core/executor/State.hpp"
#include "free_gait_core/executor/AdapterBase.hpp"
#include "free_gait_core/step/Step.hpp"
#include "free_gait_core/step/StepParameters.hpp"
#include "free_gait_core/base_motion/BaseAuto.hpp"
#include "free_gait_core/base_motion/BaseTrajectory.hpp"
#include "free_gait_core/leg_motion/EndEffectorMotionBase.hpp"
#include "free_gait_core/leg_motion/JointMotionBase.hpp"
#include "free_gait_core/leg_motion/Footstep.hpp"
#include "free_gait_core/leg_motion/LegMode.hpp"

namespace free_gait {

class StepCompleter
{
 public:
  StepCompleter(std::shared_ptr<StepParameters> parameters, std::shared_ptr<AdapterBase> adapter);
  virtual ~StepCompleter();
  bool complete(const State& state, const StepQueue& queue, Step& step) const;
  bool complete(const State& state, const Step& step, EndEffectorMotionBase& endEffectorMotion) const;
  bool complete(const State& state, const Step& step, JointMotionBase& jointMotion) const;
  bool complete(const State& state, const Step& step, const StepQueue& queue, BaseMotionBase& baseMotion) const;
  void setParameters(Footstep& footTarget) const;
  void setParameters(LegMode& legMode) const;
  void setParameters(BaseAuto& baseAuto) const;
  void setParameters(BaseTrajectory& baseTrajectory) const;

 private:
  std::shared_ptr<StepParameters> parameters_;
  std::shared_ptr<AdapterBase> adapter_;
};

} /* namespace */
