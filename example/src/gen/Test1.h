#pragma once
#include <fsmgen/fsmgen.h>

/**
* \description description for Event1
*/
struct Event1 : fsmgen::Event {
	int payload1;

};
/**
* \description 
*/
class state1 : public fsmgen::State {
public:
	void onEntry() override;

	void onUpdate() override;

	void onExit(const Event1& event);
	void onExit() override;

};
/**
* \description 
*/
class state2 : public fsmgen::State {
public:
	void onEntry(const Event1& event);

	void onUpdate() override;

	void onExit() override;

};
