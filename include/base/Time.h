#pragma once

class Time {
private:
	static Time* m_Ptr;

	float m_DeltaTime;
	float m_LastFrame;

	Time();
public:
	Time(const Time& obj) = delete;

	static Time* getInstance();

	void calcDeltaTime();
	float getDeltaTime();
};
