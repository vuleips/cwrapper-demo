#include "c_wrapper.h"
#include <vector>
#include <fstream>

using namespace std;

Kernel* createKernel(KernelContext* ctx) {
	return new Kernel(*ctx);
}

void startValidation(Kernel* kernel) {
	KernelContext ctx = kernel->GetContext();

	bool isValidSTEP(true);

	// some validation here
	if (isValidSTEP) {
		string baseFolder("DfmCheckerMock");
		vector<string> toCopies = {
			"stl.stl",
			"cylinder_info.json",
			"triangles_to_face.json"
		};

		const int bufferSize(10000);
		char* buffer = new char[bufferSize];
		for (auto toCopy : toCopies) {
			string filePath(baseFolder + "/" + toCopy);
			ifstream file(filePath, ios::binary);

			if (file.is_open()) {
				ctx.LogDebug(("[C++] Opening write " + filePath).c_str());
				auto blobid = ctx.OpenWriteData(toCopy.c_str());

				while (!file.eof())
				{
					ctx.LogDebug(("[C++] Writing " + filePath).c_str());
					file.read(buffer, bufferSize);
					ctx.WriteData(blobid, buffer, static_cast<int>(file.gcount()));
				}


				ctx.LogDebug(("[C++] Closing write " + filePath).c_str());
				ctx.CloseWriteData(blobid);
			}
			else {
				ctx.LogDebug(("[C++] File is not good: " + filePath).c_str());
			}
		}
		delete[] buffer;
	}
}

void closeKernel(Kernel* kernel) {
	delete kernel;
}
