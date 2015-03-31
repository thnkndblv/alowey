n, m, k = gets.split.map &:to_i
a = gets.split.map &:to_i
b = gets.split.map &:to_i

h = {}

a.each_with_index { |value, index| h[ value ] = index }

ans = 0
b.each do |v|
  pos = h[ v ]
  page = (pos + k) / k
  ans += page

  if pos != 0
    a[pos], a[pos - 1] = a[pos - 1], a[pos]
    h[ a[pos] ] = pos
    h[ a[pos - 1] ] = pos - 1
  end
end
puts ans
