The archive tool scart creates playback files (multiplexed miniSEED files) from
:term:`SDS` structured data (e.g. created by slarchive) or from data passed from
another record source such as :ref:`Arclink <rs-arclink>`. It can also playback
records directly out of an SDS structure. Furthermore it can be used to import
multiplexed miniSEED files into a local SDS structure.
So it is possible to save event based waveform data in combination with
scevtstreams into another archive.

.. _scart-config:

Configuration
=============

scart can make use of :ref:`global_recordstream`
implementations which are provided by additional plugins.
For loading additional plugins, e.g. the *xyz* plugin create and configure :file:`scart.cfg`:

.. code-block:: sh

   plugins = xyz

Examples
========

#. Extract data from the default :term:`SDS` archive in :file:`$SEISCOMP_ROOT/var/lib/archive`
   or from a local :term:`SDS` archive [SDS archive] into a miniSEED file :file:`file.mseed`
   and sort by end time of the records:

   .. code-block:: sh

      scart -dsvE -t '[start-time]~[end-time]' > file.mseed
	  scart -dsvE -t '[start-time]~[end-time]' [SDS archive] > [file.mseed]

   .. note::

      Sorting data is computational expensive but required for waveform playbacks.

#. Push miniSEED data from file :file:`file.mseed` into a local :term:`SDS` archive:

   .. code-block:: sh

      scart  -I file://[file.mseed] [SDS archive]

#. Collect data from an FDSNWS server using the :ref:`global_recordstream`
   interface and write to a miniSEED file. The data streams and the time spans are
   defined in a list file using the option :option:`list`. The list can be generated e.g.
   by :ref:`scevtstreams`.

   .. code-block:: sh

      scart  -I fdsnws://[server]:80 --list list.file --stdout > file.mseed

.. note::

   Repeated pushing of miniSEED data into an archive will duplicate the data.
