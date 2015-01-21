// Copyright 2014 Isis Innovation Limited and the authors of InfiniTAM

#pragma once

#include "../../ITMSceneReconstructionEngine.h"

namespace ITMLib
{
	namespace Engine
	{
		template<class TVoxel, class TIndex>
		class ITMSceneReconstructionEngine_CUDA : public ITMSceneReconstructionEngine < TVoxel, TIndex >
		{};

		template<class TVoxel>
		class ITMSceneReconstructionEngine_CUDA<TVoxel, ITMVoxelBlockHash> : public ITMSceneReconstructionEngine < TVoxel, ITMVoxelBlockHash >
		{
		private:
			int *noAllocatedVoxelEntries_device, *noAllocatedExcessEntries_device;
			int *noVisibleEntries_device, *noActiveEntries_device;

			unsigned char *entriesAllocType_device;
			Vector4s *blockCoords_device;

		public:
			void AllocateSceneFromDepth(ITMScene<TVoxel, ITMVoxelBlockHash> *scene, const ITMView *view, const ITMTrackingState *trackingState,
				const ITMRenderState *renderState);

			void IntegrateIntoScene(ITMScene<TVoxel, ITMVoxelBlockHash> *scene, const ITMView *view, const ITMTrackingState *trackingState,
				const ITMRenderState *renderState);

			ITMSceneReconstructionEngine_CUDA(void);
			~ITMSceneReconstructionEngine_CUDA(void);
		};

		template<class TVoxel>
		class ITMSceneReconstructionEngine_CUDA<TVoxel, ITMPlainVoxelArray> : public ITMSceneReconstructionEngine < TVoxel, ITMPlainVoxelArray >
		{
		public:
			void AllocateSceneFromDepth(ITMScene<TVoxel, ITMPlainVoxelArray> *scene, const ITMView *view, const ITMTrackingState *trackingState,
				const ITMRenderState *renderState);

			void IntegrateIntoScene(ITMScene<TVoxel, ITMPlainVoxelArray> *scene, const ITMView *view, const ITMTrackingState *trackingState,
				const ITMRenderState *renderState);
		};
	}
}
