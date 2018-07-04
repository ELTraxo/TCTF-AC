#pragma once
std::vector<std::reference_wrapper<Hack>> GHackVec;

void FreezeThread(Memory & mem)
{
	while (!mem.GetProcDeathVar())
	{
		if (!GHackVec.empty())
		{
			for each(Hack hack in GHackVec)
			{
				hack.WriteValue();
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}