<?php

namespace spec\Rector\PhpSpecToPHPUnit\Tests\Rector\Class_\PhpSpecToPHPUnitRector\Fixture;

use PhpSpec\ObjectBehavior;

class ExceptionSpec extends ObjectBehavior
{
    public function it_should_throw_exceptions_where_rates_are_not_loaded()
    {
        $this->beConstructedWith('https://non-existent-rates.example.com/denni_kurz.txt');

        $this->shouldThrow(RatesNotLoadedException::class)->during('get');
    }
}

?>
-----
<?php

namespace Tests\Rector\PhpSpecToPHPUnit\Tests\Rector\Class_\PhpSpecToPHPUnitRector\Fixture;

use PhpSpec\ObjectBehavior;

class ExceptionTest extends \PHPUnit\Framework\TestCase
{
    private \Rector\PhpSpecToPHPUnit\Tests\Rector\Class_\PhpSpecToPHPUnitRector\Fixture\Exception $exception;
    protected function setUp()
    {
        $this->exception = new \Rector\PhpSpecToPHPUnit\Tests\Rector\Class_\PhpSpecToPHPUnitRector\Fixture\Exception();
    }
    public function testThrowExceptionsWhereRatesAreNotLoaded()
    {
        $this->exception = new \Rector\PhpSpecToPHPUnit\Tests\Rector\Class_\PhpSpecToPHPUnitRector\Fixture\Exception('https://non-existent-rates.example.com/denni_kurz.txt');

        $this->expectException(RatesNotLoadedException::class);
        $this->exception->get();
    }
}

?>
