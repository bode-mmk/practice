<?php
    
    // 自分の事務所のアイドルの点呼

class Idol implements IteratorAggregate
{
    protected $idols = array();
    
    function __construct(array $idols){
        $this->idols = $idols;
    }
    
    function getIterator(){
        return new ArrayIterator($this->idols);
    }
}

$idols = new Idol(array("momoka","karin","yoshino"));

foreach($idols as $elements){
    print $elements;
}

