##x = -10:0.1:10; # Create an evenly-spaced vector from -10..10
##y = sin (x);    # y is also a vector
##plot (x, y);
##title ("Simple 2-D Plot");
##xlabel ("x");
##ylabel ("sin (x)");

pkg load control

# 传递函数
##num = conv([1,1],conv([1,2,6], [1,2,6]));
##den = conv([1,0,0], conv([1,3], [1,2,3,4]));
##G = tf(num, den)

# 特征根、零点、极点
p = [1,3,0,4];
r = roots(p);

poly(r);