module sw1(
				input clk,
				input rst,
				input [9:0]sw,
				output [1:0]f
);
				wire [1:0]y,x0,x1,x2,x3;
				assign y=sw[1:0];
				assign x0=sw[3:2];
				assign x1=sw[5:4];
				assign x2=sw[7:6];
				assign x3=sw[9:8];
				reg [1:0]f0;
				always @ (posedge clk) begin
								case(y[1:0])
												2'b00:assign f0=x0[1:0];
												2'b01:assign f0=x1[1:0];
												2'b10:assign f0=x2[1:0];
												2'b11:assign f0=x3[1:0];
								endcase
				end
				assign f=f0;
endmodule
