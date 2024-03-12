module add(
	input clk,
	input rst,
	input [11:0]sw,
	output [3:0]sum0,
	output [3:0]cout0,
	output overflow0
);
	integer i;
	wire [3:0]a,b,b0;
	wire en;
	reg [3:0]sum,cout;
	reg overflow;
	assign a=sw[3:0];
	assign b=sw[7:4];
	assign b0=~sw[7:4]+1;
	assign en=sw[11];
	always @ (posedge clk) begin
		if(en)	begin
			if(sw[10:8]==3'b000) begin
					for(i=0;i<4;i++) begin
							if(i==0)
								{cout[i],sum[i]}=a[i]+b[i];
							else
								{cout[i],sum[i]}=a[i]+b[i]+cout[i-1];
					end
			end
			if(sw[10:8]==3'b001) begin
					for(i=0;i<4;i++)	begin
							if(i==0)
									{cout[i],sum[i]}=a[i]+b0[i];
							else
									{cout[i],sum[i]}=a[i]+b0[i]+cout[i-1];
					end
			overflow=(cout[3]^cout[2]==1)? 1:0;
			end
	end
	end
	assign sum0=sum;
	assign cout0=cout;
	assign overflow0=overflow;
endmodule

