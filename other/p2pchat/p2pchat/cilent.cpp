
#include<boost\asio.hpp>
#include<boost\bind.hpp>
#include<iostream>
using namespace std;
using namespace boost::asio;
using boost::asio::ip::udp;

class server
{
public:
	server(boost::asio::io_service& io_service, short port)
		: socket_(io_service, udp::endpoint(udp::v4(), port))
	{
		socket_.async_receive_from(
			boost::asio::buffer(data_, max_length), sender_endpoint_,
			boost::bind(&server::handle_receive_from, this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

	void handle_receive_from(const boost::system::error_code& error,size_t bytes_recvd)
	{
		if (!error && bytes_recvd > 0)
		{
			socket_.async_send_to(
				boost::asio::buffer(data_, bytes_recvd), sender_endpoint_,
				boost::bind(&server::handle_send_to, this,
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
		}
		else
		{
			socket_.async_receive_from(
				boost::asio::buffer(data_, max_length), sender_endpoint_,
				boost::bind(&server::handle_receive_from, this,
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
		}
	}

	void handle_send_to(const boost::system::error_code& /*error*/,size_t /*bytes_sent*/)
	{
		socket_.async_receive_from(
			boost::asio::buffer(data_, max_length), sender_endpoint_,
			boost::bind(&server::handle_receive_from, this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

private:
	udp::socket socket_;
	udp::endpoint sender_endpoint_;
	enum { max_length = 1024 };
	char data_[max_length];
};

int main(int argc, char* argv[])
{
	try
	{
		boost::asio::io_service io_service;
		server s(io_service, 1000);
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
		system("pause");
	}
	system("pause");
	return 0;
}

//int main(int argc, char* argv[])
//{
//	// ����asio�඼��Ҫio_service����
//	io_service iosev;
//	ip::tcp::acceptor acceptor(iosev,ip::tcp::endpoint(ip::tcp::v4(), 1000));
//	for (;;)
//	{
//		// socket����
//		ip::tcp::socket socket(iosev);
//		// �ȴ�ֱ���ͻ������ӽ���
//		acceptor.accept(socket);
//		// ��ʾ���ӽ����Ŀͻ���
//		std::cout << socket.remote_endpoint().address() << std::endl;
//		//system("pause");
//		// ��ͻ��˷���hello world!
//		boost::system::error_code ec;
//		socket.write_some(buffer("hello world!"), ec);
//
//		// ���������ӡ������Ϣ
//		if (ec)
//		{
//			std::cout <<
//				boost::system::system_error(ec).what() << std::endl;
//			break;
//		}
//		// �뵱ǰ�ͻ�������ɺ�ѭ�������ȴ���һ�ͻ�����
//	}
//	system("pause");
//	return 0;
//}
