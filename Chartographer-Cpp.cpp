#include "Chartographer-Cpp.h"

#include "ChartographMessenger.grpc.pb.h"
#include <grpcpp/grpcpp.h>

static std::unique_ptr<ChartographMessenger::GraphPlotter::Stub> stub_;
static std::shared_ptr<grpc::Channel> serverChannel;

void ChartoGrapher::Connect(std::string address) {
	serverChannel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
	stub_ = ChartographMessenger::GraphPlotter::NewStub(serverChannel);
}

std::string ChartoGrapher::getConnectivityState()
{
	grpc_connectivity_state state = serverChannel->GetState(false);
	std::string stateString = "unknown";
	switch (state) {
	case grpc_connectivity_state::GRPC_CHANNEL_IDLE:
		stateString = "Idle";
		break;
	case grpc_connectivity_state::GRPC_CHANNEL_CONNECTING:
		stateString = "Connecting";
		break;
	case grpc_connectivity_state::GRPC_CHANNEL_READY:
		stateString = "Ready";
		break;
	case grpc_connectivity_state::GRPC_CHANNEL_TRANSIENT_FAILURE:
		stateString = "Transient Failure";
		break;
	case grpc_connectivity_state::GRPC_CHANNEL_SHUTDOWN:
		stateString = "Shutdown";
		break;
	default:
			stateString = "Unknown";
	}

	return stateString;
}

void ChartoGrapher::CreatePlot(std::string plotId) {
	if (serverChannel->GetState(true) == grpc_connectivity_state::GRPC_CHANNEL_TRANSIENT_FAILURE) return;
	grpc::ClientContext context;
	ChartographMessenger::GraphData request;
	ChartographMessenger::PlotResponse response;

	assert(!plotId.empty());

	request.set_plotid(plotId);

	grpc::Status status = stub_->CreatePlot(&context, request, &response);
	if (status.ok()) {
		std::cout << "Plot created: " << response.plotid() << std::endl;
	}
	else {
		std::cout << "Error: " << status.error_code() << ": " << status.error_message() << std::endl;
	}
}

void ChartoGrapher::UpdatePlot(std::string plotId, double x, double y) {
	if (serverChannel->GetState(true) == grpc_connectivity_state::GRPC_CHANNEL_TRANSIENT_FAILURE) return;
	grpc::ClientContext context;
	ChartographMessenger::UpdateData request;
	ChartographMessenger::PlotResponse response;
	assert(!plotId.empty());
	request.set_plotid(plotId);
	
	request.add_new_data_points();
	request.mutable_new_data_points(0)->set_x(x);
	request.mutable_new_data_points(0)->set_y(y);

	grpc::Status status = stub_->UpdatePlot(&context, request, &response);
	if (status.ok()) {
		std::cout << "Plot updated: " << response.plotid() << std::endl;
	}
	else {
		std::cout << "Error: " << status.error_code() << ": " << status.error_message() << std::endl;
	}
}

void ChartoGrapher::UpdatePlot(std::string plotId, std::vector<double[2]> points){
	if (serverChannel->GetState(true) == grpc_connectivity_state::GRPC_CHANNEL_TRANSIENT_FAILURE) return;
	grpc::ClientContext context;
	ChartographMessenger::UpdateData request;
	ChartographMessenger::PlotResponse response;

	assert(!plotId.empty());

	request.set_plotid(plotId);

	for (int i = 0; i < points.size(); i++) {
		request.add_new_data_points();
		request.mutable_new_data_points(i)->set_x(points[i][0]);
		request.mutable_new_data_points(i)->set_y(points[i][1]);
	}

	grpc::Status status = stub_->UpdatePlot(&context, request, &response);
	if (status.ok()) {
		std::cout << "Plot updated: " << response.plotid() << std::endl;
	}
	else {
		std::cout << "Error: " << status.error_code() << ": " << status.error_message() << std::endl;
	}
}
