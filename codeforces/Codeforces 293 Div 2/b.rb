s = gets
t = gets

hs = Hash.new(0)
s.split('').each { |c| hs[ c ] += 1 }

ht = Hash.new(0)
t.split('').each { |c| ht[ c ] += 1 }

a = 0
b = 0

hs.each do |k, v|
  m = [hs[k], ht[k]].min
  a += m
  hs[k] -= m
  ht[k] -= m
end

hs.each do |k, v|
  m = [hs[k], ht[ k.downcase ]].min
  b += m
  hs[ k ] -= m
  ht[ k.downcase ] += m

  m = [hs[k], ht[ k.upcase ]].min
  b += m
  hs[ k ] -= m
  ht[ k.upcase ] += m
end

puts "#{a - 1} #{b}"
