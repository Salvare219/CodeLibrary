n = gets.to_i
r = n.times.map { gets.split.map(&:to_i) }

(0...n).each { |k|
  (0...n).each { |i|
    (0...n).each { |j|
      r[i][j]=[r[i][j],r[i][k]+r[k][j]].min
    }
  }
}
puts r.flatten.max