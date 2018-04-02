#pragma once

typedef const char*(* OpenWriteDataCallback)(const char*);
typedef void(* WriteDataCallback)(const char*, const char*, int);
typedef void(* CloseWriteDataCallback)(const char*);
typedef const char*(* OpenReadDataCallback)(const char*);
typedef int(* ReadDataCallback)(const char*, char*, int);
typedef void(* CloseReadDataCallback)(const char*);
typedef void(* LogDebugCallback)(const char*);

class ExplicitContext {
public:
	OpenWriteDataCallback OpenWriteData;
	WriteDataCallback WriteData;
	CloseWriteDataCallback CloseWriteData;

	OpenReadDataCallback OpenReadData;
	ReadDataCallback ReadData;
	CloseReadDataCallback CloseReadData;

	LogDebugCallback LogDebug;
};
