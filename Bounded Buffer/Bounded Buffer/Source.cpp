#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <deque>

using namespace std;

class Buffer
{
private:

public:
	void addNum(int num)
	{
		while (true) {
			std::unique_lock<std::mutex> locker(m_mutex);
			m_con.wait(locker, [this]() {return m_buffer.size() < m_size; });
			m_buffer.push_back(num);
			locker.unlock();
			m_con.notify_all();
			return;
		}
	}

	int removeNum()
	{
		while (true)
		{
			std::unique_lock<std::mutex> locker(m_mutex);
			m_con.wait(locker, [this]() {return m_buffer.size() > 0; });
			int back = m_buffer.back();
			m_buffer.pop_back();
			locker.unlock();
			m_con.notify_all();
			return back;
		}
	}

private:
	mutex m_mutex;
	condition_variable m_con;
	deque<int> m_buffer;
	const unsigned int m_size = 10;
};

class Producer
{
private:
	Buffer & m_buffer;
	mutex m_mutex;

public:
	Producer(Buffer & buff) :
		m_buffer(buff)
	{

	};

	void run()
	{
		while (true)
		{
			// Randomise a number to add
			int randNum = rand() % 100;

			// Add to buffer
			m_buffer.addNum(randNum);
			
			// Lock mutex
			m_mutex.lock();

			// Output and sleep
			cout << "Produced : " << randNum << endl;
			this_thread::sleep_for(chrono::milliseconds(50));

			// Unlock mutex
			m_mutex.unlock();
		}
	}
};

class Consumer
{
private:
	Buffer & m_buffer;
	mutex m_mutex;

public:
	Consumer(Buffer & buff) :
		m_buffer(buff)
	{

	};

	void run()
	{
		while (true)
		{
			// Remove num from buffer
			int num = m_buffer.removeNum();

			// Lock mutex
			m_mutex.lock();

			// Output and sleep
			cout << " Consumed : " << num << endl;
			this_thread::sleep_for(chrono::milliseconds(50));

			// Unlock mutex
			m_mutex.unlock();
		}
	}
};

int main()
{
	Buffer TheBuffer;
	Producer TheProducer(TheBuffer);
	Consumer TheConsumer(TheBuffer);

	thread ProducerThread(&Producer::run, &TheProducer);
	thread ConsumerThread(&Consumer::run, &TheConsumer);

	ProducerThread.join();
	ConsumerThread.join();

	cin.get();
	
	return 0;
}